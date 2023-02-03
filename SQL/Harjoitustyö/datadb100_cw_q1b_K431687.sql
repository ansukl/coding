-- Database basics 2021
-- Course work, Query 1B
-- anna.kleemola@tuni.fi

SELECT day_of_week, start_time, gc_name, duration, level
FROM tt_class LEFT OUTER JOIN g_class
    ON tt_class.gc_id = g_class.gc_id
    LEFT OUTER JOIN category ON g_class.c_id = category.c_id
WHERE c_name LIKE 'Body maintenance' AND (level = 2 OR duration >= 60)
ORDER BY day_of_week ASC, start_time ASC, gc_name ASC;
