
/**
 * Sort table rows alphabetically based on the values in a column
 *
 * @param {Number} col column index (zero based)
 * @param {HTMLTableElement} table the table to be sorted
 */
function sortTableByColumn(col, table) {
  // TODO: Implement this function as instructed
  const tbody = table.querySelector("tbody")

  let dataArray = Array.from(tbody.children);

  //console.dir(tbody)
  //console.dir(dataArray)
  //console.log(HTMLCollection.prototype.isPrototypeOf(tbody));
  //console.log(HTMLCollection.prototype.isPrototypeOf(tbody.children));

  const sorted = dataArray.sort(function(a, b) {
    var x = a.children.item(col).innerHTML;
    var y = b.children.item(col).innerHTML;

    return x.localeCompare(y);
  });

  /*
  for (var i = tbody.children.length - 1; i >= 0; --i) {
    tbody.children[i].remove();
  }*/

  for (let i = 0; i < sorted.length; i++) {
    //console.log(table.rows.item(i + 1), sorted.at(i));
    tbody.appendChild(sorted[i])
  }
}

/**
 * DO NOT EDIT THE CODE BELOW!
 *
 * The code below is there just to make it easier to test the code.
 *
 * If your function works correctly you should be able to sort the table
 * simply by clicking any column heading and the table should be immediately
 * sorted by values in that column.
 */

// find the table element
const table = document.getElementById('sortable');

// attach an event listener to each th element's click event
table.querySelectorAll('thead th').forEach((th, i) =>
  th.addEventListener('click', () => {
    sortTableByColumn(i, table);
  })
);