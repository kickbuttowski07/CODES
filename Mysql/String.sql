/* 1. ASCII(str)
   Returns ASCII code of the first character. */
SELECT ASCII(FIRST_NAME) AS ascii_code
FROM Student WHERE STUDENT_ID=201;

/* 2. CHAR_LENGTH(str) / CHARACTER_LENGTH(str)
   Number of characters (not bytes). */
SELECT CHAR_LENGTH(FIRST_NAME) AS char_len,
       CHARACTER_LENGTH(FIRST_NAME) AS char_len2
FROM Student WHERE STUDENT_ID=201;

/* 3. LENGTH(str)
   Number of bytes in the string. */
SELECT LENGTH(FIRST_NAME) AS byte_len
FROM Student WHERE STUDENT_ID=201;

/* 4. CONCAT(str1,str2,…) – Concatenate strings. */
SELECT CONCAT(FIRST_NAME,' ',LAST_NAME) AS full_name
FROM Student WHERE STUDENT_ID=201;

/* 5. FIELD(str,str1,str2,…)
   Index of str in list (1-based, 0 if not found). */
SELECT FIELD(MAJOR,'Mathematics','Physics','Computer Science') AS field_pos
FROM Student WHERE STUDENT_ID=201;

/* 6. FIND_IN_SET(str,strlist)
   Index of str inside comma-separated list. */
SELECT FIND_IN_SET('Physics','Math,Physics,Chemistry') AS find_pos;

/* 7. FORMAT(number,decimals)
   Format number with commas and decimals. */
SELECT FORMAT(5000.4567,2) AS formatted_amount;

/* 8. INSERT(str,pos,len,newstr)
   Insert newstr into str at pos deleting len chars. */
SELECT INSERT(FIRST_NAME,2,3,'###') AS inserted
FROM Student WHERE STUDENT_ID=201;

/* 9. INSTR(str,substr)
   Position of substring in string. */
SELECT INSTR(MAJOR,'Science') AS instr_pos
FROM Student WHERE STUDENT_ID=201;

/* 10. LCASE(str) / LOWER(str)
    Convert to lowercase. */
SELECT LCASE(FIRST_NAME) AS lower1, LOWER(FIRST_NAME) AS lower2
FROM Student WHERE STUDENT_ID=201;

/* 11. UCASE(str) / UPPER(str)
    Convert to uppercase. */
SELECT UCASE(FIRST_NAME) AS upper1, UPPER(FIRST_NAME) AS upper2
FROM Student WHERE STUDENT_ID=201;

/* 12. LEFT(str,len)
    Leftmost len characters. */
SELECT LEFT(FIRST_NAME,3) AS left_part
FROM Student WHERE STUDENT_ID=201;

/* 13. RIGHT(str,len)
    Rightmost len characters. */
SELECT RIGHT(FIRST_NAME,3) AS right_part
FROM Student WHERE STUDENT_ID=201;

/* 14. LOCATE(substr,str[,start])
    Position of substring starting at optional index. */
SELECT LOCATE('Science',MAJOR) AS locate_pos
FROM Student WHERE STUDENT_ID=201;

/* 15. POSITION(substr IN str)
    Standard SQL version of LOCATE. */
SELECT POSITION('Science' IN MAJOR) AS position_pos
FROM Student WHERE STUDENT_ID=201;

/* 16. LTRIM(str)
    Remove leading spaces. */
SELECT LTRIM('    hello') AS ltrimmed;

/* 17. RTRIM(str)
    Remove trailing spaces. */
SELECT RTRIM('hello    ') AS rtrimmed;

/* 18. TRIM([BOTH|LEADING|TRAILING remstr FROM] str)
    Remove spaces or specified characters. */
SELECT TRIM('   hello   ') AS trimmed;

/* 19. SPACE(n)
    Return n spaces. */
SELECT CONCAT('Hello',SPACE(5),'World') AS spaced;

/* 20. REPEAT(str,count)
    Repeat string count times. */
SELECT REPEAT(FIRST_NAME,2) AS repeated
FROM Student WHERE STUDENT_ID=201;

/* 21. REPLACE(str,from_str,to_str)
    Replace all occurrences of from_str with to_str. */
SELECT REPLACE(MAJOR,'Science','Tech') AS replaced
FROM Student WHERE STUDENT_ID=201;

/* 22. REVERSE(str)
    Reverse the string. */
SELECT REVERSE(FIRST_NAME) AS reversed
FROM Student WHERE STUDENT_ID=201;

/* 23. STRCMP(str1,str2)
    Compare two strings; returns 0 if equal, -1 if str1<str2, 1 if str1>str2. */
SELECT STRCMP('Apple','Banana') AS cmp_result;

/* 24. SUBSTRING(str,pos,len) / SUBSTR / MID
    Substring from position pos of length len. */
SELECT SUBSTRING(MAJOR,10,7) AS sub1,
       SUBSTR(MAJOR,10,7) AS sub2,
       MID(MAJOR,10,7) AS sub3
FROM Student WHERE STUDENT_ID=201;

/* 25. SUBSTRING_INDEX(str,delim,count)
    Return substring before count occurrences of delim
    (positive from start, negative from end). */
SELECT SUBSTRING_INDEX('a,b,c,d',',',2) AS subindex1,
       SUBSTRING_INDEX('a,b,c,d',',',-2) AS subindex2;

/* 26. MID(str,pos,len) – already shown above as synonym of SUBSTRING. */
