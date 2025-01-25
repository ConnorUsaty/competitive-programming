# Write your MySQL query statement below
SELECT user_id, name, mail
FROM users
WHERE mail REGEXP "^[A-Za-z][A-Za-z0-9_\\.\\-]*@leetcode\\.com$"

# Can use REGEXP in MySQL
# Have to escape characters with \\