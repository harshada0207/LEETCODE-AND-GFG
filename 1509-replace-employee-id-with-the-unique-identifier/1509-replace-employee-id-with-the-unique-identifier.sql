# Write your MySQL query statement below
SELECT e2.unique_id, e1.name from employees as e1
LEFT JOIN employeeUNI as e2 ON e1.id=e2.id;