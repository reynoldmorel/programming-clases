import { FinalProduct } from './FinalProduct'
import { MenuItem } from './MenuItem'

import { Md5 } from 'ts-md5/dist/md5'


export class Menu {
  private id: string;
  private name: string;
  private finalProducts: Array<MenuItem>

  constructor() { }

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

  public getFinalProducts(): Array<MenuItem> {
    return this.finalProducts;
  }

  public setFinalProducts(finalProducts: Array<MenuItem>): void {
    this.finalProducts = finalProducts;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }



}