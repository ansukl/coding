-- Database basics 2021
-- Course work, Query 2C
-- anna.kleemola@tuni.fi

SELECT gc_name, duration, c_name
FROM g_class LEFT OUTER JOIN category
    ON g_class.c_id = category.c_id
WHERE duration = (SELECT MIN(duration) FROM g_class
        LEFT OUTER JOIN category
        ON g_class.c_id = category.c_id
        WHERE c_name = 'Body maintenance')
ORDER BY gc_name ASC;
