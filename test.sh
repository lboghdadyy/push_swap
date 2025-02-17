while true; do
    n=$(seq 100 | sort -R| tr '\n' ' ')
    status=$(./push_swap "$n")
    count=$(echo "$status" | wc -l)

    if [ "$count" -gt 700 ]; then
        echo "$n"
        exit 0
    fi
    sleep 0.01
done
