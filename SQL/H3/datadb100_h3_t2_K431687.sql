-- Database basics 2021
-- H3 T2
-- anna.kleemola@tuni.fi

SELECT m.name, mov.name AS predecessor_name
FROM movie AS m LEFT OUTER JOIN movie AS mov
    ON m.predecessor_id = mov.id
ORDER BY m.id ASC;
