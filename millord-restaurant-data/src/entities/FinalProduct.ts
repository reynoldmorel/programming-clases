import { Product } from './Product'



export class FinalProduct extends Product {
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
  }




}