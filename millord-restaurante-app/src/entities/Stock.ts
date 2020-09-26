
import { StockProduct } from './StockProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class Stock {
  private id: string;
  private name: string;
  private stockProducts: Array<StockProduct>

  constructor() {
  }

  public getId(): string {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getName(): string {
    return this.name;
  }

  public setName(name: string): void {
    this.name = name;
  }

  public getStockProducts(): Array<StockProduct> {
    return this.stockProducts;
  }

  public setStockProducts(stockProducts: Array<StockProduct>): void {
    this.stockProducts = stockProducts;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }



}