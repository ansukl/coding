const chai = require('chai');
const expect = chai.expect;
const chaiHttp = require('chai-http');

const registrationUrl = '/api/register';
const usersUrl = '/api/users';
const productsUrl = '/api/products';
const contentType = 'application/json';
chai.use(chaiHttp);

describe("Controllers", () => {
    describe("Products", () => {
        describe("getAllProducts()", () => {
            it('should return all products', function () {
                throw new Error("fail");
            });
            it('should not return all products if invalid method', function () {
                throw new Error("fail");
            });
            it('should not return all products if not authenticated user', function () {
                throw new Error("fail");
            });
        });
    });
    describe("Users", () => {
        describe("getAllUsers()", () => {
            it('should return all users', function () {
                throw new Error("fail");
            });
            it('should not return all users if not requested by admin role', function () {
                throw new Error("fail");
            });
        });
        describe("viewUser()", () => {
            it('should return a user view', function () {
                throw new Error("fail");
            });
            it('should not return a user view if not authenticated user', function () {
                throw new Error("fail");
            });
        });
        describe("deleteUser()", () => {
            it('should delete user if role is admin', function () {
                throw new Error("fail");
            });
            it('should not delete user if trying to delete own data', function () {
                throw new Error("fail");
            });
        });
        describe("updateUser()", () => {
            it('should update user if role is admin', function () {
                throw new Error("fail");
            });
            it('should not update user if trying to update own data', function () {
                throw new Error("fail");
            });
        });
        describe("registerUser()", () => {
            it('should register new user', function () {
                throw new Error("fail");
            });
            it('should not update user if user already exists', function () {
                throw new Error("fail");
            });
        });
    });
});