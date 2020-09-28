import { ModuleName } from 'typescript';
import { Menu } from './Menu'
import { FinalProduct } from './FinalProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class MenuItem {
<<<<<<< HEAD
  private _id?: string;
  private _menu?: Menu;
  private _finalProduct?: FinalProduct
  private _price?: number;

  constructor() { }

  get id(): string | undefined {
    return this._id;
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get menu(): Menu | undefined {
    return this._menu;
  }

  set menu(value: Menu | undefined) {
    this._menu = value;
  }

  get finalProduct(): FinalProduct | undefined {
    return this._finalProduct
  }

  set finalProduct(value: FinalProduct | undefined) {
    this._finalProduct = value
  }

  get price(): number | undefined {
    return this._price
  }

  set price(value: number | undefined) {
    this._price = value
=======
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
>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
  }




}