export interface IBase<T>{
  //data:T[];
  create(item: T): Promise<boolean>;
  update(id: string, item:T): Promise<boolean>;
  find(item: T): Promise<T[]>;
  findOne(id: string): Promise<T>;
}