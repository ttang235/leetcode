-- https://leetcode.com/problems/exchange-seats/description/

# Write your MySQL query statement below

select 
  case
    when id = (select max(id) from seat) and id % 2 = 1 then id
    when id % 2 = 0 then id - 1
    else id + 1
  end as id,
  student
from seat
order by id;

-- solution 2

select A.id, B.student from seat A, seat B where A.id + 1 = B.id and A.id % 2 = 1
union
select A.id, B.student from seat A, seat B where A.id - 1 = B.id and A.id % 2 = 0
union
select * from seat where id = (select max(id) from seat) and id % 2 = 1
order by 1, 2;
