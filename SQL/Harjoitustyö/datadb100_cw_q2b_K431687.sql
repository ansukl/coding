-- Database basics 2021
-- Course work, Query 2B
-- anna.kleemola@tuni.fi

SELECT gc_name, MIN(duration) AS duration, c_name
FROM g_class LEFT OUTER JOIN category
    ON g_class.c_id = category.c_id
ORDER BY gc_name ASC;
