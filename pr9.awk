{
    # Count characters
    chars += length($0)

    # Count words
    words += NF

    # Count lines
    lines++
}

END {
    # Print results
    print "Number of characters:", chars
    print "Number of words:", words
    print "Number of lines:", lines
}
