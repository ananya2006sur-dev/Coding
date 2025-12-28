import re

def split_line_with_quotes(line):
    # This regex splits on spaces, except when inside double quotes
    return re.findall(r'"([^"]*)"|(\S+)', line)

# Example usage:
#line = 'one "two three" four'
line = '"10.166.1.162" "172.19.86.211,10.166.0.182"  10.166.1.162 - [28/Dec/2025:17:31:54 +0530] "POST /logs HTTP/1.1" 499 0 "-" "Fluent-Bit" "172.19.86.211,10.166.0.182""10.166.8.52:30134" "30.009" "29.987" "." "1885403"'
tokens = []
for match in split_line_with_quotes(line):
    # each match is a tuple where only one group is non-empty
    tokens.append(match[0] if match[0] else match[1])
print(tokens)
