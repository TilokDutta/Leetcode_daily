# Write your MySQL query statement below
SELECT 
    ROUND(
        COUNT(*) / (SELECT COUNT(DISTINCT player_id) FROM Activity)
        ,2) AS fraction
FROM (
    SELECT a.player_id
    FROM Activity AS a
    JOIN (
        SELECT player_id,MIN(event_date) as first_date
        FROM Activity
        GROUP BY player_id
    ) b
    ON a.player_id = b.player_id AND(a.event_date = DATE_ADD(b.first_date,INTERVAL 1 DAY))) as next_date
