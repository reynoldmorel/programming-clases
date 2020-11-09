import { Product } from './Product'



export class FinalProduct extends Product {

  private _product?: Array<Product>


  get product(): Array<Product> | undefined {
    return this._product
  }

  set product(value: Array<Product> | undefined) {
    this._product

  }




}