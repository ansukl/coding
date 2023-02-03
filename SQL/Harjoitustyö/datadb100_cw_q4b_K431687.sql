-- Database basics 2021
-- Course work, Query 4B
-- anna.kleemola@tuni.fi

SELECT c_name, COUNT(g_class.gc_id) AS no_group_classes, COUNT(tt_class.gc_id) AS no_timetable_classes, COUNT(tt_class.i_id) AS no_instructors
FROM category LEFT OUTER JOIN g_class
    ON category.c_id = g_class.c_id
    LEFT OUTER JOIN tt_class
    ON g_class.gc_id = tt_class.gc_id
GROUP BY c_name
ORDER BY c_name ASC;
