with A as(
      select id,
      num,
      lead(num,1) over()as next_num,
      lead(num,2) over()as next_next_num 
  from Logs)

select distinct(num) as consecutiveNums from A where num=next_num AND num=next_next_num
/*
| id | num |
| -- | --- |
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |

output:
| consecutiveNums |
| --------------- |
| 1               |


| id | num | next_num | next_next_num |
| -- | --- | -------- | ------------- |
| 1  | 1   | 1        | 1             |
| 2  | 1   | 1        | 2             |
| 3  | 1   | 2        | 1             |
| 4  | 2   | 1        | 2             |
| 5  | 1   | 2        | 2             |
| 6  | 2   | 2        | null          |
| 7  | 2   | null     | null          |
*/
