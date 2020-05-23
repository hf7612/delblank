# set -x

# n0=`grep -n '#           TASK-PID    TGID   CPU#  ||||    TIMESTAMP  FUNCTION' $f |cut -d : -f 1`;  n2=`grep -n -F --  '{"traceEvents": [{"category":' $f|cut -d : -f 1`; let n3=$n2-3; echo sed -n "$n0,$n3\p" $f |bash;    #cut -b 56-10000 $f |sed 's/[0-9]*//g'|sort -u 
d=`dirname $(r $0)`
f=$1
filtExclude=$d/filt.systrace.exclude.txt
# filtExcludePid=/home/men/q/filt.systrace.exclude.txt.pid
f(){
n0=`grep -n '#           TASK-PID    TGID   CPU#  ||||    TIMESTAMP  FUNCTION' $f |cut -d : -f 1`;
n2=`grep -n -F --  '{"traceEvents": [{"category":' $f|cut -d : -f 1`;
t0=`grep -n '<!-- BEGIN TRACE -->' $f |cut -d : -f 1`;
# echo $t0  ' a ' $n0  ' b ' $n2  ' c ' $n0   10471  a  13595  b  80801  c  13595
if (( $t0 >0 && $n0 > 0 && $n2 > $n0 ));then 
    let n=$n0-1; 
    #
    let t1=$t0+4
    echo sed -n "1,$t1\p" $f |bash;
    #

    let n3=$n2-3; 

    # pid filte 
    
     # `grep -n '#           TASK-PID    TGID   CPU#  ||||    TIMESTAMP  FUNCTION' $f |cut -d : -f 1`; # tracer: nop
    
    
    let t2=$t1+1
    let p0=$n0-12
    if (( $t2 > 0 && $p0 > $t2 ));then 
    # echo aaaaaaaaaaaaaaa
    echo sed -n "$t2,$p0\p" $f |bash | grep -ivf $filtExclude; #$filtExcludePid;
    # echo bbbbbbbbbbbbbbb
    fi
    #
    grep '# tracer: nop' $f -B2 -A 100|grep '#           TASK-PID    TGID   CPU#  ||||    TIMESTAMP  FUNCTION' -B 100 -A 1
    #
    # echo sed -n "$t2,$p0\p" $f |bash | grep -ivf $filtExcludePid;
    let n6=$n0+2
    echo sed -n "$n6,$n3\p" $f |bash | grep -ivf $filtExclude ;    #cut -b 56-10000 $f |sed 's/[0-9]*//g'|sort -u 
    let n4=$n3+1;
    echo sed -n "$n4,10000000000\p" $f |bash; 
    #

fi
}
f