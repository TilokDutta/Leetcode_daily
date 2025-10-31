# Write your MySQL query statement below
select name as results
from(
    SELECT u.name, count(*) as no_of_rating
    from MovieRating m join Users u
    on m.user_id = u.user_id
    group by m.user_id
    order by no_of_rating desc, u.name asc
    limit 1
) uq
union all
select title as results
from(
    select m.movie_id,mo.title, avg(m.rating) as avg_rating
    from MovieRating m join Movies mo 
    on m.movie_id=mo.movie_id
    where month(m.created_at)=2 and year(m.created_at) = 2020
    group by m.movie_id
    order by avg_rating desc, mo.title asc
    limit 1
) q
