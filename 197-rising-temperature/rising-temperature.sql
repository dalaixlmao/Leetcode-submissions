-- Write your PostgreSQL query statement below
select w1.id 
from Weather w1
left join Weather w2
on w1.recordDate-w2.recordDate = 1
where w2.temperature is not NULL and  w2.temperature < w1.temperature;