"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
exports.FinalProduct = void 0;
var Product_1 = require("./Product");
var FinalProduct = /** @class */ (function (_super) {
    __extends(FinalProduct, _super);
    function FinalProduct() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Object.defineProperty(FinalProduct.prototype, "product", {
        get: function () {
            return this._product;
        },
        set: function (value) {
            this._product;
        },
        enumerable: false,
        configurable: true
    });
    return FinalProduct;
}(Product_1.Product));
exports.FinalProduct = FinalProduct;
