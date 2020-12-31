#if gcc f.c -o p1; gcc m.c -o p2; then
start=`date +%s%N`

./p1 "$1" "$2"


end=`date +%s%N`
runtime=$((end-start))
echo $start - $end = $runtime


start=`date +%s%N`

./p2 "$1" "$2"

end=`date +%s%N`
runtime=$((end-start))
echo $start - $end = $runtime


#fi
#bash run.sh ".bc...bq..bc..c...c.." ".*bc**c*"