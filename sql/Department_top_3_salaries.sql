with A as(
  select d.name as Department,
  E.name as Employee,
  E.salary,
  dense_rank() over(partition by E.departmentid order by E.salary desc) as denserank 
  from Employee E 
  join Department d on d.id=E.departmentid
  )

  select Department,Employee,Salary from A where denserank<=3

/*
| id | name  | salary | departmentId |
| -- | ----- | ------ | ------------ |
| 1  | Joe   | 85000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
| 7  | Will  | 70000  | 1            |

| id | name  |
| -- | ----- |
| 1  | IT    |
| 2  | Sales |
output:
| Department | Employee | Salary |
| ---------- | -------- | ------ |
| IT         | Max      | 90000  |
| IT         | Joe      | 85000  |
| IT         | Randy    | 85000  |
| IT         | Will     | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
*/
