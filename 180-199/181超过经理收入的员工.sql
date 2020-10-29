-- 方法一：把一个表当两个表使用
SELECT
    a.Name as Employee
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
    AND a.Salary > b.Salary;

-- 方法二：连接表
SELECT
    a.Name AS Employee
FROM
    Employee AS a
    JOIN Employee AS b ON a.ManagerId = b.Id
    AND a.Salary > b.Salary;