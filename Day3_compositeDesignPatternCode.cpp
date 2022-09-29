interface ILogWriter{
  write(message:string):void
}
class PatientInfoCSVReader{
logger?:ILogWriter;
constructor(){}
setLogWriter(logger:ILogWriter){
  this.logger=logger;
}
}
class TerminalLogger implements ILogWriter{
  write(messgae:string):void{}
}
class FileLogger implements ILogWriter{
  write(messgae:string):void{}
}
class AggregateLogger implements ILogWriter{
  loggers:Array<ILogWriter>=[];
  addLogger(logger:ILogWriter){ this.loggers.push(logger);}
  write(message:string){
   for(let i=0;i<this.loggers.length;i++){
    this.loggers[i].write(message);
   }
  }
}
const obj=new PatientInfoCSVReader ();
obj.setLogWriter(new TerminalLogger());
obj.setLogWriter(new FileLogger());
const loggers=new AggregateLogger();
loggers.addLogger(new TerminalLogger())
loggers.addLogger(new FileLogger());
obj.setLogWriter(loggers)