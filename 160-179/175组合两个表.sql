# 无论 person 是否有地址信息，都需要基于上述两表提供 person 的信息
# 所以需要左连接 Person，读取 Address 信息
SELECT
  FirstName,
  LastName,
  City,
  State
FROM
  Person
  LEFT JOIN Address ON Person.PersonId = Address.PersonId;