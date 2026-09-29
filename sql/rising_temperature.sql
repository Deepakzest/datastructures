with A as(

SELECT 
    id,
    recordDate,
    temperature,
    lag(temperature) over(order by recordDate) as previous
from Weather)

select id from A where temperature>previous

/*
| id | recordDate | temperature |
| -- | ---------- | ----------- |
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |


| id |
| -- |
| 2  |
| 4  |
*/
