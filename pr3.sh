echo "enter the directory name"
read dir
if [ -d "$dir" ]; then
    cd "$dir"
    ls > f
    exec < f
    while read line; do
        if [ -f "$line" ]; then
            if [ -r "$line" ] && [ -w "$line" ] && [ -x "$line" ]; then
                echo "$line has all permissions"
            else
                echo "$line does not have all permissions"
            fi
        fi
    done
fi
