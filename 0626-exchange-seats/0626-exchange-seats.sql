# Write your MySQL query statement below
select new_id as id, student
from (SELECT id, student, 
ifnull((case when id %2=1 and id != (select count(*) from Seat) then id+1
when id%2=0 then id-1
end),id) as new_id
from Seat) q
order by new_id asc