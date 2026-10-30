SELECT e.name
FROM Employee e
INNER JOIN Employee m
ON e.id = m.managerID
GROUP BY m.managerID
HAVING COUNT(m.managerId) >= 5