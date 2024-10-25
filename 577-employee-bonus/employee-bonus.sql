# Write your MySQL query statement below
select name, bonus
from Employee as e
left join bonus as b
on e.empId = b.empId
where b.bonus is NULL or b.bonus<1000;