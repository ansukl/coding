-- Database basics 2021
-- Course work, Query 5
-- anna.kleemola@tuni.fi

SELECT i_id, i_name
WHERE i_id NOT IN (
    SELECT i_id
   
    FROM (
        SELECT i_id, gc_id
        FROM can_instruct
            LEFT OUTER JOIN g_class
                ON can_instruct.gc_id = g_class.gc_id
                
        EXCEPT
        
        SELECT i_id, g_class.gc_id
        FROM tt_class
            LEFT OUTER JOIN g_class
                ON g_class.gc_id = tt_class.gc_id
    )
);
