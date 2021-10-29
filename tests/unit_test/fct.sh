#!/bin/zsh

EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m" 

tested_path="../../src/"
incl_path="$tested_path"
srcs="srcs"

CC="clang++"
CFLAGS=" -std=c++98 -I ../../utils -fsanitize=address -g "

if false; then
	CFLAGS+=" -fsanitize=address -g3"
fi

function pheader () {
printf "\e[0;1;94m\
# ****************************************************************************** #
#                                                                                #
#                                :::   :::   :::                                 #
#                              :+:+: :+:+:  :+: :+:                              #
#                            +:+ +:+:+ +:+ +:+                                   #
#                           +#+  +:+  +#+ +#+ +#+                                #
#                          +#+       +#+ +#+ #+#                                 #
#                         #+#       #+# #+# #+#                                  #
#                        ###       ### ### ###  containers_test                  #
#                                                                                #
# ****************************************************************************** #
\e[0m"
}

# getExecTime()
# {

# }

compile () {
	# 1=file 2=define used {ft/std} 3=output_file 4=compile_log
	$CC $CFLAGS -o "$3" -I./$incl_path -DTESTED_NAMESPACE=$2 $1 &>$4
	return $?
}

compile2 () {
	# 1=file 2=define used {ft/std} 3=output_file 4=compile_log
	$CC $CFLAGS -o "$3" -I./$incl_path -DTESTED_NAMESPACE=$2 $1 2>$4
	return $?
}

printRes () {
	# 1=file 2=compile 3=bin 4=output 5=std_compile
	b[0]="${BOLD}${GREEN}✅${EOC}"; b[1]="${BOLD}${RED}❌${EOC}";
	s_bool[0]="Y"; s_bool[1]="N";
	printf "%-35s: COMPILE: ${b[$2]} | RET: ${b[$3]} | OUT: ${b[$4]} | STD: [${s_bool[$5]}] | LEAKS: ${b[$6]} \n" $1
}

isEq () {
	[ $1 -eq $2 ] && echo 0 || echo 1
}

cmp_one () {
	# 1=path/to/file

	deepdir="deepthought"; logdir="logs"
	mkdir -p $deepdir $logdir
	container=$(echo $1 | cut -d "/" -f 2)
	file=$(echo $1 | cut -d "/" -f 3)
	testname=$(echo $file | cut -d "." -f 1)
	ft_bin="ft.$container.out"; ft_log="$logdir/ft.$testname.$container.log"
	std_bin="std.$container.out"; std_log="$logdir/std.$testname.$container.log"
	std_compile_log="std.$testname.$container.compile.log"

	compile "$1" "std" "$std_bin" $std_compile_log; std_ret=$?
	compile2 "$1" "ft"  "$ft_bin" leaks;  ft_ret=$?
	no_leaks = 1
	if [ -s leaks ]; then
        # The file is not-empty.
		no_leaks = 0
        rm -f 1
	else
		# The file is empty.
		rm -rf 1
	fi
	same_compilation=$(isEq $ft_ret $std_ret)
	std_compile=$std_ret

	if [ $std_compile -ne 0 ] && \
		cat $std_compile_log | grep "$container/common.hpp:1" &>/dev/null; then
		rm -f $std_compile_log	
		printf "${BOLD}${PURPLE}[$container/$testname] Cannot compile, please use \`./one\` to debug${EOC}\n"
		return;
	fi
	rm -f $std_compile_log

	> $ft_log; > $std_log;
	# a = time ./$ft_bin;
	# (TIMEFORMAT="%U"; time ls > /dev/null) |& tr -d .
	# time ./$std_bin;
	# var=$( { time sleep 0 } 2>&1 |  awk -F ' ' '/user/{print $9}'  | tr -d 's')
		# { time sleep 0 } 2>&1} |  awk -F ' ' '/user/{print $9}'  | tr -d 's' | read exec1
#get everything to the right of first "*user "
	# user=${var#*user }
	# foo=$({ time some_command 1>&3 2>&4;} 2>&1 | awk -F'[s.]' '/user/{print $3}')
	# printf "time : $var\n"
	# var = "ss\n"
	# echo $var
	# getExecTime $ft_bin $std_bin

	# mytime="$(time ( ./$ft_bin ) 2>&1 1>/dev/null )"
	# exec1=` echo $mytime  | awk -F ' ' '{print $2}'  | tr -d 's' | awk -F 'm' '{print $2}' `
	# mytime="$(time ( ./$std_bin ) 2>&1 1>/dev/null )"
	# exec2=` echo $mytime  | awk -F ' ' '{print $2}'  | tr -d 's' | awk -F 'm' '{print $2}' `
	# echo $mytime
	# echo $exec1
	run_time_error=0
	# if [ $exec1 \> $exec2 ];
	# then
	# 	run_time_error=1
	# fi;
	if [ $ft_ret -eq 0 ]; then
		./$ft_bin 2>/dev/null &>$ft_log; ft_ret=$?
	fi
	if [ $std_ret -eq 0 ]; then
		./$std_bin &>$std_log; std_ret=$?
	fi
	same_bin=$(isEq $ft_ret $std_ret)

	diff_file="$deepdir/$testname.$container.diff"
	diff $std_log $ft_log 2>/dev/null 1>"$diff_file";
	same_output=$?

	rm -f $ft_bin $std_bin
	[ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null

	printRes "$container/$file" $same_compilation $same_bin $same_output $std_compile $no_leaks
	rmdir $deepdir $logdir &>/dev/null
}

do_test () {
	# 1=container_name
	test_dir="$srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`

	for file in ${test_files[@]}; do
		cmp_one "$test_dir/$file"
	done
}

function main () {
	pheader
	containers=(vector map stack set)
	# containers=(vector list map stack queue deque multimap set multiset)
	if [ $# -ne 0 ]; then
		containers=($@);
	fi

	for container in ${containers[@]}; do
		printf "%40s\n" $container
		do_test $container 2>/dev/null
	done
}
