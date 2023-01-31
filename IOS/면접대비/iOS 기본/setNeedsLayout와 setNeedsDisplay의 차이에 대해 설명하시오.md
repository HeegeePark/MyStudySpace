# setNeedsLayout와 setNeedsDisplay의 차이에 대해 설명하시오.

- `setNeedsLayout()`메소드와 `setNeedsDisplay()` 메소드 모두 호출 즉시 실행되지 않고 다음 update cycle에 변경사항이 적용된다. 
- `setNeedsLayout`은 `layoutSubview()` 메소드를, `setNeedsDisplay()`는 `draw()` 메소드를 시스템이 호출하게끔 유도한다. 
- `setNeedsLayout()` 메소드는 모든 핸들러가 종료되고 권한이 main run loop로 돌아오는 시점에 view의 position이나 layout에 관한 변화를 적용시키고 `setNeedsDisplay()` 메소드는 다음 드로잉 사이클이 오면 그 때 쌓여있는 그려야할 컨텐츠들을 동시에 적용시킨다.



## setNeedsLayout

> Invalidates the current layout of the receiver and triggers a layout update during the next update cycle.

## Declaration

```swift
func setNeedsLayout()
```

## Discussion

뷰의 하위 뷰들의 레이아웃을 조정하고 싶을 때 메인스레드에서 이 메소드를 호출하세요. 이 메소드는 요청을 기록하고 즉시 반환합니다. 왜냐하면 이 메소드는 강제로 즉시 업데이트하지 않고 다음 업데이트 주기를 기다리기 때문에 여러 뷰들이 업데이트 되기 전에 여러 뷰들의 레이아웃을 무효화 시킬 수 있습니다.**(?)** 이 동작을 통해 모든 레이아웃 업데이트를 하나의 업데이트 주기로 통합할 수 있으며 일반적으로는 성능이 더 좋습니다.

이 메소드를 호출한 view는 재계산이 필요한 view라고 시스템에게 알려주며 이후 update cycle에서 `layoutSubviews()`가 호출됩니다.

setNeedsLayout메소드와 setNeedsDisplay메소드를 비교하였지만 이름만 비슷하지 행동은 전혀 다릅니다.



### setNeedsLayout() vs layoutIfNeeded()

- `layoutIfNeeded()`는 `setNeedsLayout()`과 같이 수동으로 `layoutSubviews()`를 예약하는 행위이지만 해당 예약을 바로 실행시키는 동기적으로 작동하는 메소드로, update cycle이 올 때까지 기다려 `layoutSubviews`를 호출시키는 것이 아니라 그 즉시 `layoutSubviews`를 발동시킨다.
- 만일 main run loop에서 하나의 View가 `setNeedsLayout`을 호출하고 그 다음 `layoutIfNeeded`를 호출한다면 `layoutIfNeeded`는 그 즉시 View의 값이 재계산되고 화면에 반영하기 때문에 `setNeedsLayout`이 예약한 `layoutSubviews` 메소드는 update cycle에서 반영해야할 변경된 값이 존재하지 않기 때문에 호출되지 않는다.
- 이러한 동작 원리로 `layoutIfNeeded`는 그 즉시 값이 변경되어야 하는 애니매이션에서 많이 사용
  - `setNeedsLayout`을 사용한다면 애니매이션 블록에서 그 즉시 View의 값이 변경되는 것이 아니라 추후 update cycle에서 값이 반영되므로 값의 변경은 이루어지지만 애니매이션 효과는 볼 수 없는 것
- `setNeedsLayout`과 `layoutIfNeeded`의 차이점은 **동기적으로 동작하느냐 비동기적으로 동작하느냐**의 차이



## setNeedsDisplay

> Marks the receiver’s entire bounds rectangle as needing to be redrawn.

## Declaration

```swift
func setNeedsDisplay()
```

## Discussion

이 메소드 혹은 `setNeedsDisplay(_:)`를 사용하여 view의 컨텐츠를 다시 그려야한다고 시스템에게 알려줄 수 있습니다. 이 메소드는 요청을 기록하고 즉시 반환합니다. view는 다음 드로잉 주기가 오기 전까지는 그려지지 않습니다. 다시말해 모든 view가 업데이트 되야 다시 그려집니다.
setNeedsDisplay가 호출 된 후 다음 업데이트 주기가 되고 draw메소드가 호출 될 때 해당 뷰의 업데이트들이 한번에 이뤄집니다.

> If your view is backed by a CAEAGLLayer object, this method has no effect. It is intended for use only with views that use native drawing technologies (such as UIKit and Core Graphics) to render their content.

CAEAGLLayer 객체를 사용하는 경우, 이 메소드는 효과가 없다고 합니다.

컨텐츠의 내용이나 모양이 변경될 때만 다시 그려질수있도록 이 메소드를 호출해야 합니다. 만약 view의 기하학적인 부분만 변한다면 view는 다시 그려지지 않습니다. 이 때는 메소드 호출 대신 contentMode속성을 변형하여 사용합니다.



[참조](https://velog.io/@zeke/difference-between-setNeedsLayoutsetNeedsDisplay)