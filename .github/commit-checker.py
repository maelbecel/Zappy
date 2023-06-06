import re
import sys

def check_commit_format(commit):
    pattern = r'\w+\s\([\w\s,\.\/]+\)\:\s.+\s\[\#\d+\]$'
    if re.match(pattern, commit):
        print(commit + " [OK]")
        return 0
    else:
        print(commit + " [K0]")
        return 1

# Get the commit from command-line argument
commit = sys.argv[1]

# Check the commit format
result = check_commit_format(commit)
exit(result)
