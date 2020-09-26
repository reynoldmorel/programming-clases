import { ModuleName } from 'typescript';
import { Menu } from './Menu'
import { FinalProduct } from './FinalProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class MenuItem {
  private id?: string;
  private menu?: Menu;
  private finalProduct?: FinalProduct
  private price?: number;

  constructor() {

  }


  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getMenu(): Menu | undefined {
    return this.menu;
  }

  public setMenu(menu: Menu): void {
    this.menu = menu;
  }

  public getFinalProduct(): FinalProduct | undefined {
    return this.finalProduct;
  }

  public setFinalProduct(finalProduct: FinalProduct): void {
    this.finalProduct = finalProduct;
  }

  public getPrice(): number | undefined {
    return this.price;
  }

  public setPrice(price: number): void {
    this.price = price;
  }


  public hashCode() {
    return Md5.hashStr(this.id)
  }




}