# Write your MySQL query statement below
SELECT DISTINCT l1.num as ConsecutiveNums
FROM Logs AS l1 JOIN
    Logs AS L2 JOIN 
    Logs AS L3
ON l1.id = l2.id+1 AND l1.id=l3.id+2 AND
    l1.num=l2.num AND 
    l2.num=l3.num