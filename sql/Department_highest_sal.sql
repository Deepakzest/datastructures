with A as
(
  select 
    e.name as Employee,
    d.name as Department,
    e.salary,dense_rank() over(partition by e.departmentid order by salary desc)as rn 
    from employee e join department d on e.departmentid=d.id)

select A.Department,A.Employee,A.salary from A where A.rn=1;
/*
| id | name  | salary | departmentId |
| -- | ----- | ------ | ------------ |
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |

| id | name  |
| -- | ----- |
| 1  | IT    |
| 2  | Sales |

output
| Department | Employee | salary |
| ---------- | -------- | ------ |
| IT         | Jim      | 90000  |
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
*/
