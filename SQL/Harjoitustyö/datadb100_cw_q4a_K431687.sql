-- Database basics 2021
-- Course work, Query 4A
-- anna.kleemola@tuni.fi

SELECT c_name, COUNT(gc_id) AS no_group_classes, MIN(duration) AS min_duration, MAX(duration) AS max_duration
FROM category LEFT OUTER JOIN g_class
    ON category.c_id = g_class.c_id
GROUP BY c_name
ORDER BY c_name ASC;
