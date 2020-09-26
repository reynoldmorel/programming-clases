import { ModuleName } from 'typescript';
import { Menu } from './Menu'
import { FinalProduct } from './FinalProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class MenuItem {
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
  }




}