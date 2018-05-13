# https://leetcode.com/problems/human-traffic-of-stadium/description/
# Write your MySQL query statement below

select C.* from stadium C
  left join stadium A on C.id = A.id + 2
  left join stadium B on C.id = B.id + 1
  left join stadium D on C.id = D.id - 1
  left join stadium E on C.id = E.id - 2
where 
  C.people >= 100 and (
      (D.people >= 100 and E.people >= 100) or
      (D.people >= 100 and B.people >= 100) or
      (B.people >= 100 and A.people >= 100)
    );
