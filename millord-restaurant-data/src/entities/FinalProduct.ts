import { Product } from './Product'



export class FinalProduct extends Product {
<<<<<<< HEAD
  private _product?: Array<Product>


  get product(): Array<Product> | undefined {
    return this._product
  }

  set product(value: Array<Product> | undefined) {
    this._product
=======
  private product?: Array<Product>

  constructor(product?: Array<Product>) {
    super()
    this.product = new Array<Product>()
  }

  public getProduct(): Array<Product> | undefined {
    return this.product;
  }

  public setProduct(product: Array<Product>): void {
    this.product = product;
>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
  }




}