-- Student (STUDENT_ID, FIRST_NAME, LAST_NAME, GPA, ENROLLMENT_DATE, MAJOR)
-- Program (STUDENT_REF_ID, PROGRAM_NAME, PROGRAM_START_DATE)
-- Scholarship (STUDENT_REF_ID, SCHOLARSHIP_AMOUNT, SCHOLARSHIP_DATE)

-- select:
-- similarly we can use attributes that we want(A1, A2,....)
Select *
FROM Student;

-- in this case distinct tuples 
SELECT distinct MAJOR, GPA
from student;

-- give no of unique values of the column Major, if we use count(*) it gives size of the table
-- since * means all, so count of all distinct tuples in this case is all the rows
select count(distinct MAJOR)
from student;


-- Where:
-- SELECT column1, column2, ...
-- FROM table_name
-- WHERE condition;

-- The WHERE clause is used to filter records.
-- It is used to extract only those records that fulfill a specified condition.

-- WHERE Condition;
-- condition -> =, <>, <=, >, >=, <, BETWEEN, IN, LIKE
-- Text Fields vs. Numeric Fields

-- ORDER BY:
-- Syntax:
-- SELECT column1, column2, ...
-- FROM table_name
-- ORDER BY column1, column2, ... ASC|DESC;

-- Both ASC, DESC can also used simultaneously
-- The ORDER BY keyword is used to sort the result-set in ascending or descending order.

-- Operators: OR, ANS, NOT (similar functionlity as Coding) to combine the statements
-- NOT IN, NOT BETWEEN, NOT LIKE

-- SELECT * FROM Customers
-- WHERE City NOT IN ('Paris', 'London');
-- WHERE CustomerID NOT BETWEEN 10 AND 60;
-- WHERE CustomerName NOT LIKE 'A%';
-- above where conditions can be used

-- What is a NULL Value?
-- A field with a NULL value is a field with no value.
-- If a field in a table is optional, it is possible to insert a new record or update a record without adding a value to this field. 
-- Then, the field will be saved with a NULL value.

-- Always use IS NULL, IS NOT NULL operatoors to look for NULL values.


-- UPDATE Syntax
-- UPDATE table_name
-- SET column1 = value1, column2 = value2, ...
-- WHERE condition;

-- Note: Be careful when updating records in a table! Notice the WHERE clause in the UPDATE statement. 
-- The WHERE clause specifies which record(s) that should be updated. 
-- If you omit the WHERE clause, all records in the table will be updated!



-- DELETE Syntax
-- DELETE FROM table_name WHERE condition;
-- The DELETE statement is used to delete existing records in a table.

-- Note: Be careful when deleting records in a table! Notice the WHERE clause in the DELETE statement. 
-- The WHERE clause specifies which record(s) should be deleted. 
-- If you omit the WHERE clause, all records in the table will be deleted!
-- DELETE FROM table_name; --> delete all rows

-- To delete a table we use DROP,
-- DROP TABLE table_name;

-- The SQL SELECT TOP Clause
-- The SELECT TOP clause is used to specify the number of records to return.
-- The SELECT TOP clause is useful on large tables with thousands of records. Returning a large number of records can impact performance.
-- Ex: 
SELECT top 3 * 
FROM Student
WHERE GPA > 6
ORDER BY GPA DESC;









