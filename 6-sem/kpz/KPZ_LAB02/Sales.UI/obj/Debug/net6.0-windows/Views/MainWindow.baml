   M S B A M L   `   `   `  ����C  ?Sales.UI, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null#clr-namespace:Sales.UISales.UI  5   	   /clr-namespace:Sales.UI.ViewsSales.UI.Views  5   	       Sales.UI.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   (localclr-namespace:Sales.UI     5   	   .Viewsclr-namespace:Sales.UI.Views     5   	     � Title$  
MainWindow��5	   	   $	��450��6   $
��1000��6)    � 	Resources 5         ButtonStyle �� 
TargetType �� Property �� Value  ButtonBigger �� TargetProperty W� From	 W� To g� Duration  ButtonSmaller��%}  &	        &	 �     &	 �     �� 5   
   " ��6$   .�5      ��  � ��$	 120��6&   �� 5       � ��$ 30��6'   �� 5       � ��$ 10q�6'   5      �� 5   
   .��5      W� $ Width�6    1206@    1506K   $ 0:0:0.10D�6T   5      �� 5   
   .��5      W� $ Width�6    1506@    1206K   $ 0:0:0.10D�6T   5      5      .��5      � 	 � RowDefinitions	 5   
   �� 5      $
��Auto �6   6,   �� 5      $
��Auto �6   6,   .+�5"   
   �� $��0��6   
 �� Orientation$
 
Horizontal=�6"   $��10q�6;   .+�5#      (   "Sales.UI.Views.ProductsUserControl  $
��Left=�6(   $	��Top=�6C   $��10q�6[   )   #Sales.UI.Views.CustomersUserControl  5$      $��Center=�6)   $	��Top=�6F   $��10q�6^   &    Sales.UI.Views.OrdersUserControl  5%      $��Right=�6&   $	��Top=�6B   $��10q�6Z   5&      �� 5(   
   $��1��6   $
 
Horizontal=�6"   $��10q�6;   .+�5)      �� $��Change Price��6   #��[  6,   $
��Left=�5*      ��5+      �� *ChangePriceCommand+��5,      �� *SelectedProduct+ � Triggers 5-      :� 5.       :� RoutedEvent$ 
MouseEnter��6#   .[�5/      �� #��[ 6*   50      :� 51      $ 
MouseLeave��6#   .[�52      �� #��[ 6*   53      55      �� 57      $��Change Name��6   #��[  6+   $��Center=�6P   ��58      �� *ChangeNameCommand+��6;   �� *SelectedCustomer+ 59      :� 5:      $ 
MouseEnter��6#   .[�5;      �� #��[ 6*   5<      :� 5=      $ 
MouseLeave��6#   .[�5>      �� #��[ 6*   5?      5A      �� 5B      $��Change Order Date��6   #��[  61   $��Right=�6V    5C      :� 5D      $ 
MouseEnter��6#   .[�5E      �� #��[ 6*   5F      :� 5G      $ 
MouseLeave��6#   .[�5H      �� #��[ 6*   5I      5K      5L      5O      5P      