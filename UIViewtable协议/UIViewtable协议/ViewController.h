//
//  ViewController.h
//  UIViewtable协议
//
//  Created by 张佳乔 on 2021/6/14.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
<
//普通代理协议
UITableViewDelegate,
//数据代理协议
UITableViewDataSource>
{
    //定义视图对象
    UITableView* _tableView;
    //声明一个数据源
    NSMutableArray* _arrayData;
}

@end

