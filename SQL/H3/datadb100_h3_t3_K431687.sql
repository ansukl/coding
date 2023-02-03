-- Database basics 2021
-- H3 T3
-- anna.kleemola@tuni.fi

SELECT m.name, mov.name AS sequel_name
FROM movie AS m LEFT OUTER JOIN movie AS mov
    ON m.id = mov.predecessor_id
ORDER BY m.id ASC;
