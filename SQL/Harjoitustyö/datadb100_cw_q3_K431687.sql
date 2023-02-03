-- Database basics 2021
-- Course work, Query 3
-- anna.kleemola@tuni.fi

SELECT instructor.i_id, i_name
FROM instructor LEFT OUTER JOIN can_instruct
    ON instructor.i_id = can_instruct.i_id
    LEFT OUTER JOIN g_class
    ON can_instruct.gc_id = g_class.gc_id
    LEFT OUTER JOIN category
    ON g_class.c_id = category.c_id
WHERE c_name = 'Indoor cycling'
INTERSECT
SELECT instructor.i_id, i_name
FROM instructor LEFT OUTER JOIN can_instruct
    ON instructor.i_id = can_instruct.i_id
    LEFT OUTER JOIN g_class
    ON can_instruct.gc_id = g_class.gc_id
    LEFT OUTER JOIN category
    ON g_class.c_id = category.c_id
WHERE c_name = 'Body maintenance'
ORDER BY instructor.i_id ASC;
