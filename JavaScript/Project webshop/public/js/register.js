/**
 * TODO: 8.4 Register new user
 *       - Handle registration form submission
 *       - Prevent registration when password and passwordConfirmation do not match
 *       - Use createNotification() function from utils.js to show user messages of
 *       - error conditions and successful registration
 *       - Reset the form back to empty after successful registration
 *       - Use postOrPutJSON() function from utils.js to send your data back to server
 */

const form = document.getElementById("register-form");

form.addEventListener("submit", function (event) {
    event.preventDefault();
    const formData = new FormData(form);
    const name = formData.get("name");
    const email = formData.get("email");
    const password = formData.get("password");
    const passwordConf = formData.get("passwordConfirmation");

    if (password !== passwordConf) {
        createNotification("Passwords do not match", "notifications-container", false);
        return;
    }

    postOrPutJSON("/api/register", 'POST', { "name": name, "email": email, "password": password }).then(
        response => {
            createNotification("Registration success", "notifications-container", true);
            form.reset();
            return;
        }
    ).catch(err => {
        createNotification("Registration failed", "notifications-container", false);
        return;
    });
  });