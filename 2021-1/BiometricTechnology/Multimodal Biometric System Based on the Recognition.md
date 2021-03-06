# Multimodal Biometric System Based on the Recognition of Face and Both Irises

- ref : [https://journals.sagepub.com/doi/full/10.5772/50869](https://journals.sagepub.com/doi/full/10.5772/50869)

# Abstract

- 단일 모드 생체 인식 시스템 (얼굴 또는 지문과 같은 단일 양식 기반)의 성능은 조명 변화, 피부 상태 및 환경 조건, 장치 변화와 같은 다양한 문제와 경쟁해야 함.
    - → 다중 모드 생체 인식 시스템은 단일 모드 생체 인식의 한계를 극복하고 고정밀 인식을 제공하기 위해 사용되었음.
- 본 논문에서는 얼굴과 홍채 인식의 점수 수준 융합을 기반으로 한 새로운 다중 모드 생체 인식 시스템을 제안함.

- 이 논문에서 가지는 새로운 특징
    1. 제안되는 장치는 얼굴과 두 홍채 이미지를 동시에 획득 가능
        - 안면 카메라, 홍채 카메라 2개, 근적외선 조명 장치 및 콜드 미러로 구성
    2. 빠르고 정확한 홍채 감지는 얼굴 이미지에서 감지된 홍채의 크기를 기준으로 홍채 이미지에서 수행되는 두개의 원형 가장자리 감지를 기반으로 함.
    3. 서포트 벡터 머신(SVM)을 사용하여 얼굴과 두 홍채에 대한 각 점수를 결합하면, 결합 된 정확도가 향상됨.

- 실험 결과 제안 된 방법의 동일 오차율은 0.131 %로 얼굴 또는 홍채 인식 및 기타 융합 방법보다 낮은 것으로 나타남.

### Keywords

`Multimodal biometrics`, `Score level fusion`, `Support Vector Machine`

---

# 1. Introduction

### 생체 인식

- 생체 인식은 얼굴, 홍채, 손가락 정맥 또는 보행과 같은 생리적 또는 행동 적 특성을 사용하여 개인을 식별하는 데 가장 널리 사용되는 접근 방식 중 하나
- 생체 인식 시스템은 스마트 카드 또는 암호를 기반으로하는 기존 인증 시스템과 달리 사람이 카드를 휴대하거나 정보를 기억할 필요가 없기 때문에 유리함.
- 소유 기반 인증 시스템은 키와 토큰이 공유, 잘못 배치, 복제, 분실 또는 도난 될 수 있다는 단점이 있지만 생체 인식 시스템은 이러한 문제 방지 가능
- 따라서 생체 인식은 많은 응용 분야에서 채택됨.

**BUT**, 단일 모드 생체 인식 시스템 (얼굴 또는 지문과 같은 단일 양식을 기반으로 함)은 조명 변화, 피부 상태 및 환경, 장치 변화와 같은 몇 가지 문제에 직면함.

### 단일 모드 생체 인식 문제점

- 얼굴 인식 : 얼굴 포즈, 표정, 다양한 조명 조건에 의해 쉽게 저하
- 홍채 인식 : 홍채 인식 성능은 홍채 영역을 숨기는 근적외선(NIR) 광 반사 영역(짙은 속눈썹 및 입력 이미지의 초점 흐림)에 의해 크게 영향 받음.

→ 단일 모드 생체 인식의 한계를 극복하기 위해 다중 모드 생체 인식에 많은 관심

→ 멀티 모달 생체 인식은 **둘 이상의 인간 생리적 또는 행동적 특성을 기반으로 개인을 식별하는 것**을 목표로 함.

- 다중 모드 생체 인식의 핵심 문제는 더 나은 인식 결과를 생성하기 위해 각 양식의 여러 기능을 결합하는 데 사용되는 방법

### 다중 모드 생체 인식 융합(multimodal biometric fusion) 수행 기준

- 다중 모드 생체 인식 시스템 정보의 융합은 세 가지의 다른 레벨에 의해 수행될 수 있음.
    - feature level (기능 수준)
    - matching score level (매칭 점수 수준)
    - decision level (결정 수준)
- 인기있는 방법 : **matching score level에서 융합하는 것**
    - 서로 다른 매칭 시스템의 점수 조합을 용이하게 하기 때문

### 얼굴 및 홍채 인식을 기반으로 한 다중 모드 생체 인식 시스템 선행 연구

- 얼굴과 홍채 인식을 기반으로하는 이전의 멀티 모달 생체 인식 시스템은 홍채 인식의 정확도가 높고 얼굴 인식이 편리하기 때문에 **얼굴과 단일 홍채 기능을 사용**
- BUT, 시스템 복잡성이 증가하기 때문에 얼굴과 두 홍채의 조합에 대한 연구는 거의 없음.

    → 한 사람의 홍채는 다른 사람의 홍채와 다른 것으로 알려져 있기 때문에, 
    얼굴과 홍채의 정보를 결합하여 더 높은 정확도를 보장하는 새로운 다중 모드 생체 인식 방법을 제안함.

- 추가로, 그들의 실험에서 얼굴과 홍채 데이터는 같은 사람의 얼굴과 홍채임에도, 얼굴과 홍채의 **서로 다른 Open Database를 결합함으로써 획득**되었음.
    
    - 얼굴과 홍채가 완벽하게 상관 관계가 없다는 가정에 기초
- BUT, 이러한 가정을 확인하기 위해서는 집중적인 통계 분석이 필요

    → 본 논문에서는 얼굴과 홍채에 대한 두 개의 서로 다른 Open Database 대신, 
    **사람으로부터 실제로 획득한 얼굴과 두 홍채에 대한 데이터로 실험 수행**

### 얼굴과 홍채의 이미지를 동시에 캡처하기 위해 제안된 장치

- 구성 : 얼굴 카메라, 홍채 카메라 2 개, NIR 조명, 콜드 미러
- 빠르고 정확한 홍채 감지 알고리즘
    1. 얼굴 이미지에서 홍채 크기 감지
    2. 감지된 홍채 이미지에서 두 개의 CED (Circular Edge Detection) 수행
- 얼굴과 두 홍채에 대한matching scores를 SVM (Support Vector Machine) 기반으로 인식 및 결합하여 정확도가 향상

---

# 2. Proposed Multimodal Biometric System

## 2.1. 제안된 촬영 장치

<p align="center">
  <img src="./images_m/Untitled 0.png">

  그림 1. 제안된 이미지 캡처 장치
</p>

- 그림 1은 얼굴과 두 홍채의 이미지를 동시에 캡처하기 위해 제안된 장치
- 안면 카메라, 홍채 카메라 2 개, 콜드 미러 및 근적외선 (NIR) 조명기 (파장 880nm의 36 개의 NIR 발광 다이오드 [LED] 포함)로 구성
- 3 대의 USB (Universal Serial Bus) 카메라 (Logitech Corp[11]에서 제작 한 Webcam C600)를 사용하여 초당 30 프레임의 속도로 1600 × 1200 픽셀이 포함 된 이미지를 캡처함.
    - 하나의 USB 카메라는 안면 카메라로 사용
    - 다른 하나는 고정 초점 줌 렌즈가 있는 홍채 카메라로 사용
    - 홍채 인식 처리 시간을 줄이기 위해 캡처된 홍채 이미지의 크기도 800 × 600 픽셀로 축소
- 고정 초점 줌 렌즈를 사용한다는 것은 우리 장치가 홍채 이미지에 필요한 해상도를 제공했음을 의미
    - 제안한 장치로 캡처한 홍채의 평균 직경은 180–280 픽셀, Z 거리(카메라 렌즈와 사용자의 눈 사이의 거리) 작동 범위는 25–40cm
    - By ISO / IEC 19794-6, 홍채의 직경이 200 픽셀 이상인 홍채 이미지는 "양호한" 품질로 간주
    (150 ~ 200 픽셀은 "허용", 100 ~ 150 픽셀은 "한계")

        → 우리의 홍채 이미지는 홍채 직경 측면에서 **"허용"및 "양호"품질에 대한 요구 사항을 충족**함.

## 2.2. 제안된 method의 Overview

<p align="center">
  <img src="./images_m/Untitled 1.png">

  그림 2. 제안된 method의 Overview
</p>

### 얼굴 인식 프로세스

1. 얼굴과 눈 영역은 AdaBoost와 빠른 eye detection에 의해 감지
2. 검출된 얼굴 영역의 variation을 제거하기 위해 크기 정규화가 수행되고, 조명은 Retinex 알고리즘을 사용하여 정규화
3. 주성분 분석 (PCA)을 기반으로 정규화 된 얼굴 이미지에서 얼굴 특징 획득
4. matching score는 SVM에 대한 입력을 제공하기 위해 유클리드 거리로 계산

### 홍채 인식 프로세스 (왼쪽 및 오른쪽 홍채 이미지 모두 수행)

1. 홍채 인식 중에 홍채 영역은 정수 기반 CED와 눈꺼풀 / 속눈썹 detection 방법을 사용하여 image segmentation
2. 홍채 코드는 segmented iris region에서 생성
3. Hamming 거리의 matching score가 계산되어 SVM 입력으로 사용

→ 얼굴과 두 홍채의 matching score는 SVM 입력으로 사용되며 최종 인증(authentication)은 SVM의 출력을 기반으로 수행함.

## 2.3. 얼굴 인식 방식

<p align="center">
  <img src="./images_m/Untitled 2.png">

  그림 3. 제안된 방법을 사용하여 감지 된 얼굴 및 눈 영역
</p>

<p align="center">
  <img src="./images_m/Untitled 3.png">

  그림 4. 크기 및 조명 정규화 후 얼굴 영역
</p>

1. AdaBoost 알고리즘을 사용하여 얼굴 영역을 감지
2. 두 눈은 그림 3과 같이 빠른 eye detection에 의해 발견되며 감지된 얼굴 영역은 두 눈의 위치에 따라 재정의됨.
3. Z 거리에 따라 얼굴 영역의 크기 변화를 줄이기 위해 크기 정규화가 수행

    → 재정의된 얼굴 영역의 정규화 크기 : 32 × 32 픽셀

4. 얼굴 영역에 조명 변화로 인한 얼굴 인식 성능이 저하를 방지하기 위해, Retinex 전처리가 조명 정규화에 사용
5. 얼굴 특징 추출
    - 주성분 분석 (PCA), 선형 판별 분석(LDA), 국소 이진 패턴(LBP)과 같은 많은 얼굴 인식 기술이 이전 연구에서 제안되었으나,
    - 본 연구에서는 얼굴 이미지 표현에 능하기 때문에 특징 선택 및 차원 축소에 널리 사용되는 기술인 **PCA**를 사용
6. 입력된 얼굴 특징 벡터와 등록된 템플릿 특징 벡터 사이의 유클리드 거리를 기반으로 얼굴 인식을 위한 matching score 계산

## 2.4. 홍채 인식 방법

- 캡처 된 홍채 이미지에는 홍채, 동공, 공막, 눈꺼풀 및 속눈썹이 포함됨.

- 이미지에서 홍채 영역을 분리하기 위해 두 개의 CED를 수행(Integro-differential 값은 홍채의 반경 값과 중앙 위치를 변경하면서 홍채 (및 동공)의 안쪽과 바깥 쪽 경계 사이에서 계산됨.)

- 가변 줌 렌즈 대신 고정 줌 배율의 줌 렌즈를 사용
    - Z-distance 작동 범위는 25–40cm이고, 시스템 크기를 줄이고 줌 렌즈 작동시 추가 모터 사용을 피하기 위해

    → 따라서 캡처된 이미지의 평균 홍채 직경은 180–280 픽셀

    - 두 개의 CED에 대한 반경 검색 범위는 다양한 직경 (180-280)의 홍채 영역을 감지하기 위해 이보다 컸고, 이는 처리 및 홍채 영역 감지 정확도 측면에서 홍채 인식 성능을 저하시킬 수 있음.

    <p align="center">
  <img src="./images_m/Untitled 4.png">
    
      그림 5. 감지된 홍채, 눈꺼풀 및 속눈썹 영역의 예. (a) 원본 이미지. (b) Localized regions
    </p>
    
    

### 위 문제를 극복하기 위한 방법

1. 섹션 2.3에서 언급했듯이 두 눈은 빠른 eye detection을 사용하여 발견되며 얼굴 카메라로 캡처한 이미지에서 홍채의 크기를 결정함.
    - **calibration** 후 얼굴 이미지와 홍채 이미지의 홍채 크기 간의 관계를 얻을 수 있음.
    - 이 관계를 바탕으로 두 CED의 반경 검색 범위로 사용되는 홍채 카메라로 캡처한 이미지에서 홍채의 크기를 추정이 가능함. → 처리 시간, 홍채 감지 오류 **down**
2. 눈꺼풀 감지 마스크와 포물선 형 Hough 변환을 사용하여 눈꺼풀 감지
3. 속눈썹을 감지하기 위해 속눈썹 마스크 사용
    - (b)는 감지 된 홍채, 눈꺼풀 및 속눈썹 영역의 예
4. 1 차원 Gabor 필터를 사용하여 분할된 영역에서 홍채 코드를 추출
5. 등록된 홍채 코드와 입력된 홍채 코드 간의 해밍 거리(HD)를 기반으로 홍채 인식을 위한 matching score 계산

## 2.5. 얼굴과 두 홍채 인식을 위한 세 점수 결합

1. SVM에 대해 MIN-MAX 스케일링을 사용하여 계산된 HD 및 ED(유클리드 거리)의 범위를 0–1로 정규화
    - 세 matching score들은 서로 다른 거리 측정 범위 값으로 생성되기 때문
2. 세 가지 정규화 된 점수는 SVM에 대한 세 가지 입력 값으로 사용(세 가지 matching score가 SVM의 입력으로 사용)
3. 감마 값이 8 인 RBF 커널을 SVM 커널 및 매개변수로 채택
    - 일반적으로 커널 기능과 해당 매개 변수의 선택은 SVM 분류 성능에 영향을 줌.
    - LIBSVM 프로그램을 사용하여 선형 커널, 다항식 커널, RBF (radial base function) 커널 및 시그 모이 드 커널의 성능을 비교하여(최적의 커널 및 커널 매개 변수는 훈련 데이터베이스를 사용한 5 배 교차 검증에 의해 결정) 위 커널이 SVM에 최적으로 확인
4. SVM 훈련을 위해 authentic(genuine) 및 imposter 데이터를 각각 "1"및 "-1"로 할당
5. SVM 출력에 대한 최소 EER(Equal Error Rate)을 얻을 수 있는 최적 임계값(optimal threshol)이 결정
    - EER는 FAR이 FRR과 거의 같을 때의 오류율로, 기존의 생체 인식 시스템의 정확도를 나타내는 데 널리 사용

---

# 3.  Experimental Results

<p align="center">
  <img src="./images_m/Untitled 5.png">

  그림 6. 얼굴과 두 홍채를 캡처한 이미지의 예
</p>



- 제안된 시스템의 정확도를 측정하기 위해 제안된 장치를 사용하여 Z 거리 범위가 25-40cm 인 얼굴과 두 홍채의 이미지를 획득함.
- 지상 실측(ground-truth) Z 거리는 레이저 빔 (BOSCH DLE 70 전문 모델)을 사용하여 측정
- 그림 6은 서로 다른 Z 거리로 캡처 한 이미지를 보여줌



### 표 1 ~ 3과 그림 7과 같이 테스트 데이터베이스를 사용하여 시스템 성능을 평가

- 데이터베이스에는 30 명의 총 3,450 개의 이미지 (얼굴 이미지 1,150 개, 왼쪽 홍채 이미지 1,150 개, 오른쪽 홍채 이미지 1,150 개)가 포함되어 있음.

- SVM은 최적의 분류기를 결정하기 위해 훈련 데이터베이스가 필요
    
    - 수집된 이미지의 절반(각각 1,725 개의 이미지 [얼굴 이미지 575 개, 왼쪽 홍채 이미지 575 개 및 오른쪽 홍채 이미지 575 개])이 훈련 데이터로, 나머지 이미지는 테스트 데이터로 사용됨.
    
- 훈련 데이터베이스
    - 얼굴 인식에 있어서는 genuine 샘플(positive 샘플) 수는 10,774개, imposter 샘플(negative 샘플) 수는 각각 154,251 개
    - 왼쪽 또는 오른쪽 홍채 인식의 경우 genuine(10,774) 샘플과 imposter(154,251) 샘플도 각각 얼굴 인식과 동일

    
    
- 표 1의 첫 번째 실험에서는 EER를 기반으로 얼굴 및 홍채 인식의 정확도를 측정

- 홍채 인식의 정확도는 얼굴 인식의 정확도보다 약간 나음.
    
- 홍채 카메라가 가변 초점 렌즈가 아닌 고정 초점 렌즈를 사용했기 때문에 Z 거리가 25 또는 40cm 인 경우 초점이 맞지 않는 이미지가 종종 얻어져 홍채 인식 성능이 저하되기 때문
    
    
    
- 다음 실험에서는 표 2와 같이 서로 다른 유형의 SVM 커널을 사용할 때 조합 방법의 성능을 비교

- 모든 경우에 세 가지 matching score를 사용하여 제안 된 방법이 가장 좋은 성능을 나타냄.



- 그림 7은 얼굴, 왼쪽 홍채 및 오른쪽 홍채 인식을 위한 세 가지 match score 기반 테스트 데이터의 3D 분포
- 그림 7은 낮은 false acceptance and rejection error rates로 genuine 데이터와 imposter 데이터를 분리 할 수 있음을 확인
- 표 3은 기존 fusion method와의 각 조합에 대한 EER를 보여줌.
    - Min-Max 규칙을 사용하여 최종 점수는 각각 최소 및 최대 입력 점수를 선택하여 결정
    - 표 3에서 볼 수 있듯이 우리가 제안한 방법의 정확도는 다른 fusion method보다 우수함.



- 홍채 인식의 경우, 심하게 (광학 또는 움직임) blur 홍채 이미지 또는 눈꺼풀, 속눈썹, 머리카락 또는 정반사에 의해 홍채 영역이 극도로 가려지는 홍채 이미지는 제안된 시스템의 성능에 영향을 미칠 수 있음
- 심한 off-angle의 홍채 이미지 (사용자가 홍채 카메라에서 멀리 떨어진 위치를 응시할 때 이미지가 캡처 됨)도 성능에 영향을 미칠 수 있음.
- 얼굴 인식의 경우, 얼굴이 심하게 회전 (pan or tilt)되는 얼굴 이미지와 극단적인 표정 (놀라움, 찡그린 얼굴 등)이 시스템 성능에 영향을 미칠 수 있음.

<p align="center">
  <img src="./images_m/Untitled 6.png">

  표 1. 단일 인식 방법의 정확도 (단위 : [%])
</p>



<p align="center">
  <img src="./images_m/Untitled 7.png">

  표 2. 커널이 다른 SVM을 사용한 조합 방법의 정확도 (단위 : [%])
</p>



<p align="center">
  <img src="./images_m/Untitled 8.png">

  표 3. 기존 fusion methodfmf 사용한 EER 비교 (단위 : [%])
</p>



<p align="center">
  <img src="./images_m/Untitled 9.png">
  그림 7. 테스트 데이터베이스와 함께 RBF 커널을 사용한 SVM 분류 결과
</p>



---

# 4.  Conclusion

- SVM을 기반으로 성능을 향상시키기 위해 얼굴과 두 홍채 인식을 결합한 새로운 다중 모드 생체 인식 시스템을 제안
- 제안된 장치는 얼굴과 두 홍채의 이미지를 동시에 캡처
- 실험 결과는 제안된 시스템이 다른 조합 방법뿐만 아니라 개별적으로 얼굴 또는 홍채 인식보다 더 나은 성능을 발휘하는 것으로 나타남.
- 앞으로 우리는 얼굴, 홍채 및 정맥과 같은 더 많은 양식을 결합하는 방법을 조사할 계획