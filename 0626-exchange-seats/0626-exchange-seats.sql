# Write your MySQL query statement below
SELECT new_id AS id,student
FROM 
    (SELECT id, student, 
    IFNULL(
        (CASE WHEN id %2=1 AND id != (SELECT count(*) 
        FROM Seat) THEN id+1
        WHEN id%2=0 THEN id-1
        END),
    id) AS new_id
    FROM Seat) q
ORDER BY new_id ASC