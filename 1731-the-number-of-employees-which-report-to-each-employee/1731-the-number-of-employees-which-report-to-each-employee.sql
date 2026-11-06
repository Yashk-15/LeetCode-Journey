SELECT e.employee_id , e.name , COUNT(m.employee_id) AS reports_count, ROUND(AVG(m.age)) AS average_age
FROM employees e
JOIN employees m
ON m.reports_to = e.employee_id
GROUP BY e.employee_id, e.name
ORDER BY e.employee_id